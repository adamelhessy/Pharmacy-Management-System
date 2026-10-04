<div align="center">

# 🌍 Translator

**Translate text between 97 languages in one click.**

[![Live Demo](https://img.shields.io/badge/Live_Demo-Open_App-2f5bea?style=for-the-badge&logo=vercel&logoColor=white)](https://translator-beige-iota.vercel.app)

![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![Bootstrap](https://img.shields.io/badge/Bootstrap-7952B3?style=for-the-badge&logo=bootstrap&logoColor=white)

</div>

<!-- Add a screenshot: save it as screenshot.png in the repo, then uncomment the line below -->
<!-- ![Translator screenshot](screenshot.png) -->

---

## ✨ Features

| | Feature | Details |
|---|---|---|
| 🌐 | **97 languages** | From Arabic, English and French to Amharic, Maori and Zulu |
| ⚡ | **Auto-built dropdowns** | Generated from a single `countries` object in the code |
| 🎯 | **Smart defaults** | Starts as English → Arabic when the page loads |
| ✅ | **Input validation** | Shows "No Text Added" for empty text and "Choose two different languages" for matching selects |
| 🛟 | **Error handling** | Friendly message if the translation request fails |
| 🌙 | **Dark interface** | Built with Bootstrap, responsive on desktop and mobile |
| 📦 | **Zero setup** | No build step, no framework, nothing to install |

---

## 🛠️ Built with

- 🟧 **HTML, CSS and vanilla JavaScript**
- 🟪 [**Bootstrap**](https://getbootstrap.com/) for layout and styling
- 🎨 [**Font Awesome**](https://fontawesome.com/) for icons
- 🔄 [**MyMemory Translation API**](https://mymemory.translated.net/doc/spec.php) for the translations

---

## 📁 Project structure

```
translator/
├── 📂 .vscode/
├── 📂 css/
│   ├── all.min.css          Font Awesome
│   ├── bootstrap.min.css    Bootstrap
│   └── index.css            Custom styles
├── 📂 js/
│   └── index.js             App logic
└── 📄 index.html            Page markup
```

---

## 🚀 Getting started

**1. Clone the repository**

```bash
git clone https://github.com/adamelhessy/translator.git
cd translator
```

**2. Open the app**

Open `index.html` in your browser, or use the Live Server extension in VS Code.

> [!NOTE]
> An internet connection is required, because translations come from the MyMemory API.

---

## 🧠 How it works

1. 📚 The `countries` object in `js/index.js` maps language codes (like `ar-SA`) to names (like `Arabic`).
2. 🔽 On load, the script fills both dropdowns from that object.
3. 🖱️ When you click **Translate**, the script checks the input and sends the text and language pair (`from|to`) to the MyMemory API.
4. 📝 The translated text from the response appears in the output box.

---

## ➕ Adding or renaming a language

Edit the `countries` object in `js/index.js`. The dropdowns update automatically.

```js
const countries = {
  "ar-SA": "Arabic",
  "en-GB": "English",
  // add a new entry here: "code": "Name"
};
```

---

## ⚠️ Limitations

> [!WARNING]
> The free MyMemory API has a daily usage limit and a limit on text length per request.

- Translation quality varies by language pair, and some less common languages may return poor results.

---

<div align="center">

Made with ❤️ by [adamelhessy](https://github.com/adamelhessy)

</div>
