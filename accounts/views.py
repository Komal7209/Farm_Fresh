from django.shortcuts import *
from django.contrib import auth
from django.contrib.auth.models import User

# Create your views here.
def login(request):
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(username=username, password=password)
        if user is not None:
            auth.login(request, user)
            return redirect('index')
        else:
            return HttpResponse('login Failed')
    else:
        return render(request, 'accounts/Login_Page.html')

def signup_user(request):
    return render(request, "accounts/Signup_page.html")

def signup_seller(request):
    return HttpResponse("signup_seller")

def logout(request):
        if request.method == 'POST':
            auth.logout(request)
        return redirect('index')

def register(request):
    if request.method == 'POST':
        first_name = request.POST['first_name']
        last_name = request.POST['last_name']
        username = request.POST['username']
        email = request.POST['email']
        password = request.POST['password']
        password2 = request.POST['password2']
        if password == password2:
            if User.objects.filter(username=username).exists():
                return redirect('accounts/register')
            else:
                if User.objects.filter(email=email).exists():
                    return redirect('accounts/register')
                else:
                    user = User.objects.create_user(username=username, password=password, email=email,
                                                    first_name=first_name, last_name=last_name)
                    user.save()
                    return HttpResponse("<h1>you are registered</h1>")

        else:
            return redirect('accounts/register')
    else:
        return render(request, 'accounts/Signup_page.html')