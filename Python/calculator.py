import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLineEdit, QPushButton, QGridLayout

class Calculator(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Calculator')
        self.setGeometry(100, 100, 400, 600)

        self.layout = QVBoxLayout()
        
        self.screen = QLineEdit(self)
        self.layout.addWidget(self.screen)
        
        self.buttonsLayout = QGridLayout()
        
        buttons = [
            '7', '8', '9', '/', 'C',
            '4', '5', '6', '*', '(',
            '1', '2', '3', '-', ')',
            '0', '.', '=', '+'
        ]
        
        row, col = 0, 0
        for button in buttons:
            b = QPushButton(button, self)
            b.clicked.connect(self.on_click)
            self.buttonsLayout.addWidget(b, row, col)
            col += 1
            if col == 5:
                col = 0
                row += 1
        
        self.layout.addLayout(self.buttonsLayout)
        self.setLayout(self.layout)

    def on_click(self):
        button = self.sender()
        text = button.text()
        
        if text == 'C':
            self.screen.clear()
        elif text == '=':
            try:
                result = eval(self.screen.text())
                self.screen.setText(str(result))
            except:
                self.screen.setText("Error")
        else:
            self.screen.setText(self.screen.text() + text)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    calc = Calculator()
    calc.show()
    sys.exit(app.exec_())