static String indexHtml = "<!DOCTYPE html><html><head>    <meta name='viewport' content='width=device-width, initial-scale=1.0'>    <title>Light Control</title>    <style>        body {            background-color: #081b29;            font-family: Courier, Monospace;            Color: #e9edf0;            padding: 0vw 5vw;        }        a {            color: #e9edf0;            text-decoration: none;            font-size: 5vw;            text-align: center;            border-style: solid;            border-width: 3px;            padding: 15px 32px;            display: inline-block;            width: 50%;            margin: 0 auto;            margin-left: 15%        }        a:hover {            color: #ebb0b0;        }    </style></head><body>    <h1 style='font-size:10vw; text-align:center'>Light Control</h1>    <table style='border-collapse: collapse; width: 100%;' border='0'>        <tbody>            <tr>                <td style='width: 50%;'><a id='on' onclick='ChangeState()'>ON</a></td>                <td style='width: 50%;'><a id='off' onclick='ChangeState()'>OFF</a></td>            </tr>        </tbody>    </table></body><script>    window.onload = (event) => {        fetch(`/api`)            .then(response => response.text())            .then(function (response) {                if (response == 'ON') {                    document.querySelector('#off').style.cssText = '';                    document.querySelector('#on').style.cssText = 'pointer-events: none;opacity: 0.6';                }                if (response == 'OFF') {                    document.querySelector('#on').style.cssText = '';                    document.querySelector('#off').style.cssText = 'pointer-events: none;opacity: 0.6';                }            });    };    function ChangeState() {        fetch(`/api`)            .then(response => response.text())            .then(function (response) {                if (response == 'ON') {                    fetch(`/api?Light=off`)                        .then(response => response.text())                        .then(function (response) {                            document.querySelector('#off').style.cssText = 'pointer-events: none;opacity: 0.6';                            document.querySelector('#on').style.cssText = '';                            console.log(response);                        });                }                if (response == 'OFF') {                    fetch(`/api?Light=on`)                        .then(response => response.text())                        .then(function (response) {                            document.querySelector('#on').style.cssText = 'pointer-events: none;opacity: 0.6';                            document.querySelector('#off').style.cssText = '';                            console.log(response);                        });                }            });    }</script></html><!-- Important: please don't use any double quotes in this document-->";
