from django.db import models
from django.contrib.auth.models import User

# # Create your models here.
class products(models.Model):
    product_name = models.CharField(max_length=100)
    photo_main = models.ImageField(upload_to='photos/%Y/%m/%d')
    def __str__(self):
            return self.product_name

    class Meta:
        verbose_name_plural = 'Products'

class post(models.Model):
    pid = models.ForeignKey(products,on_delete=models.CASCADE)
    uid = models.ForeignKey(User,on_delete=models.CASCADE)
    product_price = models.IntegerField(blank=False)
    def __str__(self):
        return post.pid




