package com.example.sortings

fun main() {
    val array = intArrayOf(4, 7, 1, 3, 7)

    for (i in 0..(array.size - 1)) {
        for (j in 0..(array.size - 2 - i)) {
            if (array[j] > array[j + 1]) {
                val temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
            }
        }
    }

    println(array.asList())
}