from django.shortcuts import *

def demo(request):
    return render(request,"demo.html")

def index(request):
    return render(request, "shop/home.html")