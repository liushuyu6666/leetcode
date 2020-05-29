### overview
This is https://leetcode.com/problems/reverse-words-in-a-string/  

### pay attention
it seems that you need to reverse in the original string, or the memory will overflow

### submissions 
Runtime: 4 ms, faster than 80.43% of C online submissions for Reverse Words in a String.  
Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Reverse Words in a String.  
https://leetcode.com/submissions/detail/346144091/ 




### explanation
#### the first algorithm
<pre>
  0:  
    _ _ A B X Y Z _ _ C D E F _ _ _  
    
  1: reverse  
    _ _ _ F E D C _ _ Z Y X B A _ _  
      
  2: find the first word with the front space  
    _ _ _ F E D C _ _ Z Y X B A _ _  
    p     wb   we  
                i  
    
  3: reverse the word and update p  
    C D E F _ _ _ _ _ Z Y X B A _ _  
            p     i  
            
  4: i go forward to find another new word, when if find the beginning of a new word, p will go ahead on grid.  
    C D E F _ _ _ _ _ Z Y X B A _ _  
              p       i(now i find a new word)  
              
  5: find the whole word  
    C D E F _ _ _ _ _ Z Y X B A _ _  
              p      wb      we  
                              i  
  6: go to 3 reverse the word and update p  
    C D E F _ A B X Y Z _ _ _ _ _ _  
                        p     i  
                        
  7: i go to the end of the string  
    C D E F _ A B X Y Z \0_ _ _ _ _  
    
</pre>

#### the second algorithm
<pre>
stack in stack out when reverse word

  1:
    _ A B C _        stack: _ _ _ _ _ _
    p                       j
  
  2:
    _ A B C _        stack: A _ _ _ _ _
    p i                       j
    
  3:
    _ A B C _        stack: A B _ _ _ _
    p   i                       j
    
  4:
    _ A B C _        stack: A B C _ _ _
    p     i                       j
    
  5:
    C _ B C _        stack: A B _ _ _ _
      p   i                     j
      
  6:
    C B _ C _        stack: A _ _ _ _ _
        p i                   j
        
  7:
    C B A _ _        stack: _ _ _ _ _ _
          p                 j
          i
 
</pre>
            
    

