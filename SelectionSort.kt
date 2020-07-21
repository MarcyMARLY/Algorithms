package com.example.sortings

fun main() {
    val array = intArrayOf(4, 7, 1, 3, 6)

    for (i in array.indices) {
        var minInd = i
        for (j in i+1 .. (array.size-1)) {
            if (array[j] < array[minInd]) {
               minInd = j
            }
        }
        val temp = array[minInd]
        array[minInd] = array[i]
        array[i] = temp
    }

    println(array.asList())
}