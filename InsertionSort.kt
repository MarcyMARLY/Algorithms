fun main() {
    val array = intArrayOf(4, 7, 1, 3)

    for (i in array.indices) {
        for (j in i+1 until array.size) {
            if (array[j] < array[i]) {
                val temp = array[i]
                array[i] = array[j]
                array[j] = temp
            }
        }
    }

    println(array.asList())
}