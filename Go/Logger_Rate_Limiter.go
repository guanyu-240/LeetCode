type Logger struct {
    logs map[string]int
}

/** Initialize your data structure here. */
func Constructor() Logger {
    return Logger{logs: make(map[string]int)}
}


/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
func (this *Logger) Shouldprintmessage(timestamp int, message string) bool {
    ts,exists := this.logs[message]
    if exists {
        if timestamp - ts < 10 { return false }
    }
    this.logs[message] = timestamp
    return true
}


/**
 * Your Logger object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Shouldprintmessage(timestamp,message);
 */
