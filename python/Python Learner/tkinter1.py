import tkinter as tk


class APP:
    def __init__(self,master):
        frame = tk.Frame(master)
        frame.pack(side=tk.LEFT, padx=20, pady=20)
        self.hi = tk.Button(frame, text="SAY HI", fg='blue', command=self.say_hi)
        self.hi.pack()

    def say_hi(self):
        print("SAY HI")


root = tk.Tk()
app = APP(root)
root.mainloop()