(define/contract (majority-element nums)
  (-> (listof exact-integer?) exact-integer?)
  (for/fold ([candidate 0] 
             [cnt       0]
             #:result candidate) 
             ([num (in-list nums)]) 
    (cond [(= cnt 0) (values num 1)]
          [(= num candidate) (values candidate (+ cnt 1))]
          [else (values candidate (- cnt 1))])
    )
)