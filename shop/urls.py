from django.urls import path
from .views import *

urlpatterns = [
    path('cart', cart),
    path('index', index),
    # path('signup',signup),

]
