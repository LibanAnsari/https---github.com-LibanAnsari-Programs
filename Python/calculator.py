import tkinter as tk

def click(event):
    text = event.widget.cget("text")
    if text == "=":
        try:
            result = str(eval(screen.get()))
            screen.set(result)
        except Exception as e:
            screen.set("Error")
    elif text == "C":
        screen.set("")
    else:
        screen.set(screen.get() + text)

root = tk.Tk()
root.title("Calculator")
root.geometry("400x600")

screen = tk.StringVar()
entry = tk.Entry(root, textvar=screen, font="lucida 20 bold")
entry.pack(fill=tk.BOTH, ipadx=8, pady=10, padx=10)

button_frame = tk.Frame(root)
button_frame.pack()

buttons = [
    '7', '8', '9', '/', 'C',
    '4', '5', '6', '*', '(',
    '1', '2', '3', '-', ')',
    '0', '.', '=', '+', 
]

row = 0
col = 0
for button in buttons:
    b = tk.Button(button_frame, text=button, font="lucida 15 bold")
    b.grid(row=row, column=col, ipadx=10, ipady=10, padx=5, pady=5)
    b.bind("<Button-1>", click)
    col += 1
    if col == 5:
        row += 1
        col = 0

root.mainloop()