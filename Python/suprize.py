import random
import turtle
import multiprocessing

def windows():
    window = turtle.Screen()
    window.title("IF HELL EXISTS THEN THIS IS IT, IF HELL DOES NOT EXISTS THEN THIS CREATES IT!!!")

    colors = ["red", "blue", "green", "yellow", "orange", "brown"]

    t = turtle

    t.pensize(100)
    t.bgcolor(random.choice(["white", "black"]))
    t.speed(1000)

    for x in range(360):
        t.pencolor(colors[x%len(colors)])
        t.pensize(x/50)
        t.forward(x)
        t.left(59)

    window.mainloop()


def main():

    processes: list[multiprocessing.Process] = []

    for _ in range(999):
        process = multiprocessing.Process(target=windows)
        processes.append(process)
        process.start()

    for process in processes:
        process.join()

main() if __name__ == "__main__" else None
