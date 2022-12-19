def foo(arr,s):
    if(len(s) == 3):
        print(s)
        return;
    
    for i in arr:
        s += str(i);
        arr.remove(i)
        foo(arr,s)
        


foo([1,2,3],"");