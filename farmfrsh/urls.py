"""farmfrsh URL Configuration

The `urlpatterns` list routes URLs to
    1. Import the include() function: from django.urls import include, pathviews. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path,include
from .views import *

urlpatterns = [
    path('admin/', admin.site.urls),
    path('demo/', demo),
    path('', index, name='index'),
    path('accounts/', include('accounts.urls')),
    path('shop/', include('shop.urls')),
]
