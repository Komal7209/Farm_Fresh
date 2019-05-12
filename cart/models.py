from django.db import models
from shop.models import *
from django.contrib.auth.models import User

# Create your models here.
class cart(models.Model):
    post = models.ForeignKey(post, on_delete=models.DO_NOTHING)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    qty = models.IntegerField()