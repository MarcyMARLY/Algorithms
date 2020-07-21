package com.example.sortings

fun main() {
    val pat: String = "AAAA"
    val text: String = "AAAAABAAABA"

    KMP(pat, text)
}

private fun KMP(pat: String, text: String): Int {
    val patLength: Int = pat.length
    val textLength: Int = text.length

    val lps = IntArray(patLength)

    var j = 0 //for pat
    var i = 0 //for text

    computeLPS(pat, patLength, lps)

    while (i < textLength) {
        if (pat[j] == text[i]) {
            j++
            i++
        }
        if (j == patLength) {
            println(i - j)
            j = lps[j-1]
        } else if (i < textLength && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j-1]
            } else {
                i = i + 1
            }
        }
    }

    return -1
}

private fun computeLPS(pat: String, patLength: Int, lps: IntArray) {
    var len = 0
    var i = 1
    lps[0] = 0

    while (i < patLength) {
        if (pat[i] == pat[len]) {
            len++
            lps[i] = len
            i++
        } else {
            if (len != 0) {
                len = lps[len - 1]
            } else {
                lps[i] = len
                i++
            }
        }
    }
}