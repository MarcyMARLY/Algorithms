package com.example.sortings

fun main() {
    val array = intArrayOf(4, 7, 1, 3, 7)
    val dup = array.clone()
    sort(array, dup, 0, array.size - 1)
    println(array.asList())
}

private fun sort(arr: IntArray, dup: IntArray, lo: Int, hi: Int) {
    if (hi <= lo) return
    val mid = (lo + hi) / 2

    sort(arr, dup, lo, mid)
    sort(arr, dup, mid + 1, hi)
    merge(arr, dup, lo, mid, hi)
}

private fun merge(arr: IntArray, dup: IntArray, lo: Int, mid: Int, hi: Int) {

    System.arraycopy(arr, lo, dup, lo, hi - lo + 1)

    var i = lo
    var j = mid + 1

    for (k in lo..hi) {
        when {
            i > mid -> arr[k] = dup[j++]
            j > hi -> arr[k] = dup[i++]
            dup[j] < dup[i] -> arr[k] = dup[j++]
            else -> arr[k] = dup[i++]
        }
    }
}