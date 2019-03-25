class Network {
    static Request(file) {
        return new Promise(function (resolve, reject) {
            var request = new XMLHttpRequest()
            request.open("GET", file)
            request.onreadystatechange = function () {
                if (request.readyState === XMLHttpRequest.DONE)
                    resolve(request.responseText)
            }
            request.onerror = reject
            request.send()
        })
    }
    static Send(url, data) {
        return new Promise(function (resolve, reject) {
            const request = new XMLHttpRequest()
            request.open("POST", url)
            request.onreadystatechange = function () {
                if (request.readyState === XMLHttpRequest.DONE)
                    resolve(request.responseText)
            }
            request.onerror = reject
            request.send(data)
        })
    }
    static Socket(url) {
        return new Promise(function (resolve, reject) {
            let socket = new WebSocket(url)
            socket.onopen = function () {
                resolve(socket)
            }
            socket.onerror = function (err) {
                reject(err)
            }
        })
    }
}