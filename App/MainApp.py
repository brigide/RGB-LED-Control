from kivy.uix.screenmanager import Screen, ScreenManager
from kivymd.app import MDApp
from kivymd.uix.boxlayout import MDBoxLayout
from kivy.graphics import Color
import requests
from kivymd.uix.label import MDLabel

r = 0
g = 0
b = 0


class SM(ScreenManager):
    def off(self):
        requests.get("http://192.168.0.53/turnOff")
        txt = "a fita está apagada"
        self.ids.stts.text = txt

    def red(self):
        m = requests.get("http://192.168.0.53/turnRed")
        txt = "a fita está vermelha"
        self.ids.stts.text = txt

    def green(self):
        requests.get("http://192.168.0.53/turnGreen")
        txt = "a fita está verde"
        self.ids.stts.text = txt

    def blue(self):
        requests.get("http://192.168.0.53/turnBlue")
        txt = "a fita está azul"
        self.ids.stts.text = txt

    def yellow(self):
        requests.get("http://192.168.0.53/turnYellow")
        txt = "a fita está amarela"
        self.ids.stts.text = txt

    def purple(self):
        requests.get("http://192.168.0.53/turnPurple")
        txt = "a fita está roxa"
        self.ids.stts.text = txt

    def cyan(self):
        requests.get("http://192.168.0.53/turnCyan")
        txt = "a fita está ciano"
        self.ids.stts.text = txt

    def rainbow(self):
        requests.get("http://192.168.0.53/rainbowEffect")
        txt = "a fita está fading"
        self.ids.stts.text = txt


class Welcome(Screen):
    pass


class MainWindow(Screen):
    def status(self):
        self.ids.stts.text(str(r) + " " + str(g) + " " + str(b))


class MainApp(MDApp):
    def build(self):
        self.theme_cls.primary_palette = "Purple"
        return SM()


MainApp().run()