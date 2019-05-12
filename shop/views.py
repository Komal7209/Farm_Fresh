from django.shortcuts import *
from django.contrib.auth.models import User


# Create your views here.
def cart(request):
    return  render(request, "shop/checkout.html")

def index(request):
    return  render(request, "shop/index.html")

# def signup(request):
#     if request.method == 'POST':
#         user_form = UserForm(request.POST, instance=request.user)
#         profile_form = UserProfileForm(request.POST,instance=request.user)
#         if user_form.is_valid() and profile_form.is_valid():
#             profile_form.user = request.user
#             user_form.save()
#             profile_form.save()
#             messages.success(request, ('Your profile was successfully updated!'))
#             return redirect('settings:profile')
#         else:
#             messages.error(request, ('Please correct the error below.'))
#     else:
#         user_form = UserForm(instance=request.user)
#         profile_form = UserProfileForm(instance=request.user)
#     return render(request, 'accounts/Signup_page.html', {
#         'user_form': user_form,
#         'profile_form': profile_form
#     })


