import sys,os
import tkinter as tk
import tkinter.filedialog as tkfd
import tkinter.messagebox as tkmb
import shutil
installAccept=0

#Before you ask, yes, this installer is very hacky, and yes, I know it's not the best way to do it,
#but its good enough, and it works, so I'm not going to change it. (I couldnt anyway because this code is an unreadable mess)

def resource_path(relative_path):#PyInstaller stuff
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

def cancelInstall(x=0):
    sys.exit()
#open a tkinter window
root=tk.Tk()
#set the font size
root.option_add("*Font", "Helvetica 12")
#set the title
root.title("StoopidC Installer")
#set the icon
try:
    root.iconbitmap(resource_path("icon.ico"))#I think it might work now? idk
except:
    pass
#set the size
root.geometry("480x360")
#make it not resizable
root.resizable(0,0)
#add a label
label=tk.Label(root,text="Do you want to install StoopidC?")
#allign to top left
label.pack(anchor="nw",padx=5, pady=5)
#add a yes and no button
yesButton = tk.Button(
    text="Yes!",
    width=10,
    height=1
)
noButton = tk.Button(
    text="Cancel!",
    width=10,
    height=1
)
#add the buttons to the window, and make then allign to the bottom right.
yesButton.place(x=460,y=350,anchor="se")
noButton.place(x=350,y=350,anchor="se")
root.protocol("WM_DELETE_WINDOW", cancelInstall)
#function to run when yes button is clicked
def yes(x=0):
    global installAccept
    label.pack_forget()
    installAccept=1
    root.quit()
#function to run when no button is clicked
def no(x=0):
    installAccept=0
    sys.exit()
#bind the buttons to the functions
noButton.bind("<Button-1>",no)
yesButton.bind("<Button-1>",yes)
root.mainloop()
if installAccept:
    installdir="%appdata%\\stoopid"
    #resolve path
    installdir=installdir.replace("%appdata%",os.getenv("APPDATA"))
    
    #root=tk.Tk()
    #set the title
    root.title("Stoopid Installer")
    #set the size
    root.geometry("480x360")
    #make it not resizable
    root.resizable(0,0)
    #add a label
    label=tk.Label(root,text="Where do you want to install stoopid?")
    label2=tk.Label(root,text=f"Current directory: {installdir}")
    #allign to top left
    #add a yes and no button
    yesButton = tk.Button(
        text="Continue!",
        width=10,
        height=1
    )
    noButton = tk.Button(
        text="Cancel!",
        width=10,
        height=1
    )
    changeButton=tk.Button(
        text="Change installation directory",
        width=25,
        height=1
    )
    pathAdd=tk.IntVar()
    addToPath=tk.Checkbutton(
        text="Add stoopid to PATH",
        variable=pathAdd,
        onvalue=1,
        offvalue=0
    )
    #add the buttons to the window, and make then allign to the bottom right.
    yesButton.place(x=460,y=350,anchor="se")
    noButton.place(x=350,y=350,anchor="se")
    changeButton.place(x=240,y=350,anchor="se")
    label.pack(anchor="nw",padx=5, pady=5)
    label2.pack(anchor="nw",padx=5, pady=0)
    addToPath.pack(anchor="nw",padx=5, pady=40)
    #function to run when yes button is clicked
    def yes(x=0):
        root.quit()
    #function to run when no button is clicked
    def no(x=0):
        sys.exit()
    def chanceLocation(x=0):
        global installdir
        installdir=tkfd.askdirectory()
        label2.config(text=f"Current directory: {installdir}")
    #bind the buttons to the functions
    noButton.bind("<Button-1>",no)
    yesButton.bind("<Button-1>",yes)
    changeButton.bind("<Button-1>",chanceLocation)
    root.mainloop()
    
    if not os.path.exists(installdir):
        os.mkdir(installdir)
    files=[
    "build\\stoopid.exe",
    "stoopid.exe"
    ]
    #install the requirements
    
    for file in files:
        os.system("copy %s %s" % (file,installdir))
    #add the path to the environment variables
    user=os.getenv("USERNAME")
    #get the path for the current user
    cpath=os.popen("reg query \"HKCU\Environment\" /v PATH").read()
    
    cpath=cpath.split("REG")[1].strip()
    while cpath[0]!=" ":
        cpath=cpath[1:]
    cpath.strip()
    print(pathAdd)
    if (not installdir in cpath) and pathAdd:
        cpath+=";%s" % installdir
        #print(cpath)
        command="setx PATH \"%s\"" % cpath
        print(command)
        os.system(command)
        print("Added %s to PATH" % installdir)
        print("You can now run stoopid by typing stoopid in your terminal")
    else:
        if installdir in cpath:
            print("Stoopid is already in path")
        print("Not adding to path...")
    print("Installation complete!")
    tkmb.showinfo(title="Stoopid Installer",message="Installation complete!\nInstaller will now close")
else:
    print("Installation cancelled")