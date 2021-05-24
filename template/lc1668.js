/**
 * @param {string} sequence
 * @param {string} word
 * @return {number}
 */
var maxRepeating = function(sequence, word) {
    var tword = word, i = 0
    while (sequence.indexOf(tword) != -1) {
        i++
        tword += word
    }
    return i
};