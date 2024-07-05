package org.example;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;

public class JavaExercise2 {
    private static class CachingPrimeChecker {
        boolean restart = false;
        private final Map<Long, Boolean> cache;
        private Map<Long, Object> locks;
        static volatile int doneCount = 0;

        CachingPrimeChecker() {
            cache = new HashMap<>();
            locks = new HashMap<>();
        }

        public boolean isPrime(final long x) {
            synchronized (getLock(x)) {
                if (cache.containsKey(x)) {
                    doneCount++;
                    return cache.get(x);
                } else {
                    boolean isPrime = computeIfIsPrime(x);
                    cache.put(x, isPrime);
                    doneCount++;
                    return isPrime;
                }
            }
        }


        private boolean computeIfIsPrime(long x){
            final String currentThreadName = Thread.currentThread().getName();
            System.out.printf("\t[%s]Running computation for : %d%n",currentThreadName,x);
            try{
                // simulating loss computations
                Thread.sleep(TimeUnit.SECONDS.toMillis(1));
            } catch (InterruptedException e){
                throw  new RuntimeException();
            }
            if(x<2){
                return false;
            }
            for (long i = 2; i * i <= x; i++){
                if(x % i == 0){
                    return false;
                }
            }
            return true;
        }

        public static void main(String[] args) throws InterruptedException, IOException {
            CachingPrimeChecker primeCache = new CachingPrimeChecker();
            Scanner scanner = new Scanner(System.in);

            ExecutorService es = Executors.newFixedThreadPool(4);
            System.out.println("Enter 4 numbers:");
            boolean exit = false;
            int inputCounter = 0;
            long[] nums = {-1,-1,-1,-1};
            while (!exit) {
                String s = scanner.nextLine();
                String[] words = s.split("\\s+");

                for (String comm : words) {
                    if (comm.equals("quit")) {
                        exit = true;
                        break;
                    } else {
                        nums[inputCounter++] = Integer.parseInt(comm);
                        if (inputCounter == 4) {
                            break;
                        }
                    }
                }
                if (exit) {
                    break;
                }

                if (inputCounter == 4) {
                    for (int i = 0; i < 4; i++) {
                        long num = nums[i];
                        es.submit(() -> {
                            boolean isPrime = primeCache.isPrime(num);
                            System.out.println("Number: " + num + " is prime: " + isPrime);
                        });
                    }
                    while (doneCount != 4) {
                        System.out.println("wait");
                        Thread.sleep(200);
                    }

                    while (System.in.available() > 0) {
                        System.in.read();
                    }

                    doneCount = 0;
                    inputCounter = 0;
                }
            }

            scanner.close();
        }

        private Object getLock(long number) {
            synchronized (locks) {
                return locks.computeIfAbsent(number, k -> new Object());
            }
        }
    }
}
