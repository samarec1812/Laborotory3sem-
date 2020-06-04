package main


type Values struct {
	 value *int
	 flag bool
}

func Merge2Channels(f func(int) int, in1 <-chan int, in2 <-chan int, out chan<- int, n int) {

		go func() {
			    valuesArray := make([] Values, n*2)


               go func() {
                        indexI := 0
               for _, r := range valuesArray {
               	if !r.flag{
					return
				}
				   for i := indexI; i < n; i++ {

					   if valuesArray[i].value != nil && valuesArray[i+n].value != nil {
						   out <- *(valuesArray[i].value) + *(valuesArray[i+n].value)

					   } else {
						   break
					   }
				   }
			   }
			   }()

			    channels := func(inputChannel <-chan int, arr []Values){
			    	 for index := 0; index < n; index++ {
			    	 	valueInput := <-inputChannel
			    	 	go func(index int, valueInput int){
			    	 		     valueOutput := f(valueInput)
			    	 	         arr[index] = Values{&valueOutput, true}                
	    	    	}(index, valueInput)
					 }
				}
				go channels(in1, valuesArray[:n])
			    go channels(in2, valuesArray[n:])
		}()
}
