int DoSomething(StackADT s, int value) {
    int count = 0;
    if(IsEmpty(s)){
        Push(s, value);
        return 0;
    }
    int index = s->size-1;
    int blockingheight = value;
    // counting numbers smaller than value
    for(index; index>=0; index--){
        if(s->arr[index] < value){
            count++;
        }
        else if(s->arr[index] == value){
            count++; break;
        }
        else{
            break;
        }
    }
    // counting numbers larger than value
    for(index; index>=0; index--){
        if(s->arr[index] > blockingheight){
            count++;
            blockingheight = s->arr[index];
        }
    }
    Push(s, value);
    return count;
}