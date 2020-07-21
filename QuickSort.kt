package com.example.sortings

fun main() {
    val array = intArrayOf(4, 7, 1, 3, 7)
    sort(array, 0, array.size - 1)
    println(array.asList())
}

private fun sort(arr: IntArray, lo: Int, hi: Int) {
    if (hi <= lo) return
    val mid = partition(arr, lo, hi)

    sort(arr, lo, mid - 1)
    sort(arr, mid + 1, hi)
}

private fun partition(arr: IntArray, lo: Int, hi: Int): Int {
    val pivot = arr[hi] // to compare
    var i = lo - 1 // current iterator pos

    for (k in lo..hi - 1) {
        if (arr[k] < pivot) {
            i++
            val temp = arr[i]
            arr[i] = arr[k]
            arr[k] = temp
        }
    }
    val temp = arr[i + 1]
    arr[i + 1] = arr[hi]
    arr[hi] = temp

    return i + 1
}