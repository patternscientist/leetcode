(define/contract (max-sub-array nums)
  (-> (cons/c exact-integer? (listof exact-integer?)) exact-integer?)
    (define first-num (first nums))
    (for/fold ([best first-num]
               [ending-here first-num]
               #:result best)
               ([x (in-list (rest nums))])
            (define next-ending (max x (+ x ending-here)))
            (define next-best (max best next-ending))
            (values next-best next-ending))
  )