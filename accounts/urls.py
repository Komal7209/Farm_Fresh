from django.urls import path
from .views import *

urlpatterns = [
    path('login', login, name='login'),
    path('logout', logout, name='logout'),
    path('signup', signup_user),
    path('signup_seller', signup_seller),
    path('register',register,name='register'),
]