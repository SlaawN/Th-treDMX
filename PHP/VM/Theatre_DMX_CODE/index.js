import React, { useState, useEffect, useCallback } from "react";
//HELP https://www.npmjs.com/package/@lourenci/react-kanban#oncarddragend
import ReactDOM from "react-dom";
import Board, { removeCard, moveCard, addCard } from "@lourenci/react-kanban";
import styled from "styled-components";
import "./styles.css";
import $ from "jquery";

//représente l'etat du composant avec un board, 2 colonnes et des scènes
const boardData = {
  lanes: [
    {
      id: 0,
      title: "Listes Scènes",
      cards: [
        {
          id: 1,
          idBdd: 1,
          title: "Couché de soleil",
          description: "Lumières roses puis jaunes",
          Candelete: false,
          bgcolor: "#FF00F0",
          dureeSecond: 3,
          img:
            "http://www.posepartagemedia.com/images/ctrb/balancebymcroh-d6288b0.jpg"
        },
        {
          id: 2,
          idBdd: 3,
          title: "Orage et Tonnerre",
          description: "lumières stroboscopiques blanches et bleues",
          Candelete: false,
          bgcolor: "#F00F00",
          dureeSecond: 1,
          img:
            "https://drscdn.500px.org/photo/1002115102/m%3D900/v2?sig=86a8bad5a8867dc5ea970d6fda11cc1ee90c24785e145e090043abf50d9a651b"
        },
        {
          id: 3,
          idBdd: 8,
          title: "Flammes",
          description: "lumières jaunes rouges puis jaunes",
          Candelete: false,
          bgcolor: "#FFF00F",
          dureeSecond: 2,
          img:
            "https://image.shutterstock.com/image-photo/panorama-burning-fire-flames-260nw-609521522.jpg"
        },
        {
          id: 4,
          idBdd: 2,
          title: "Forêt Verte",
          description: "Echainement de lumières vertes et jaunes",
          Candelete: false,
          bgcolor: "#0f0ff0",
          dureeSecond: 4,
          img:
            "https://image.shutterstock.com/image-photo/forest-panorama-260nw-498073144.jpg"
        }
      ]
    },
    {
      id: 1,
      title: "Programe",
      cards: [
        {
          id: 9,
          idBdd: 4,
          title: "Matin Marin",
          description: "lumière bleu, verte et blanche",
          Candelete: true,
          bgcolor: "#0f0ff0",
          dureeSecond: 3,
          img:
            "http://www.360x180.fr/medias/spheriques/france/34/600-pic_st_loup_nuit/pic_st_loup_nuit.jpg"
        }
      ]
    }
  ]
};

const YourLaneHeader = styled.div`
  height: 50px;
`;

//permet de creer une div avec un style
const SceneCard = styled.div`
  border-radius: 3px
  padding: 0px;
  margin-bottom: 7px;
  ${({ dragging }) => dragging && `box-shadow: 2px 2px grey;`}
  position:absolute;
  top:0px;
  width:100%;
`;
const SceneCardBack = styled.div`
  background-image: url(${props => props.img});
  background-color: ${props => props.bgcolor};
  background-size: inherit;
  background-position-x: 0;
  background-position-y: 0;
  background-repeat: no-repeat;
  opacity: 0.5;
  padding: 0px;
  margin-right: -20px;
  left: 0px;
`;
const SceneCardBackLight = styled.div`
  background-image: url(${props => props.img});
  background-size: inherit;
  background-position-x: 0;
  background-position-y: 0;
  background-repeat: no-repeat;
  opacity: 1;
  padding: 0px;
  margin-right: -20px;
  position: absolute;
  left: 0px;
  top: 0;
`;

const SendMessageToApi = function(id) {
  /*fetch("https://192.168.65.249/api.php?msg=" + id, {
    method: "GET"
  })
    .then(function(response) {
      console.log(response);
    })
    .catch(function(err) {
      console.log("erreur API" + err);
    });*/
     /*var ws = new WebSocket("ws://192.168.1.98:8080/echo");
  ws.onmessage = function(evt) {
    console.log(evt.data);
  };
  ws.onopen = function(evt) {
    ws.send("Je suis un script javascript" + id);
  };
  ws.close();*/
};

//methode qui permet de stoper toutes les animes css et de
//lancer l'anime loading sur la scène en cours avec id et d'une durée definit dans durreesecond
function Animate(id, dureeSecond, board, click) {
  if (board === 0 || click === true) {
    $(".loading").each(function() {
      $(this)
        .stop(false, false)
        .width("10%");
    });

    $(".maskScene").each(function() {
      $(this)
        .stop(false, false)
        .css({ left: 0 });
    });

    $(".sceneLight").each(function() {
      $(this)
        .stop(false, false)
        .width("10%");
    });
  }

  $("#Mask" + id).animate({ left: "-110px" }, 200);

  $("#Load" + id).animate(
    { width: "100%" },
    dureeSecond * 1000,
    "",
    function() {
      if (board === 0) {
        $("#Load" + id).animate({ width: "10%" }, 1, "", function() {
          $("#Mask" + id).animate({ left: "0px" }, 200);
        });
      }
    }
  );

  $("#sceneLight" + id).animate(
    { width: "100%" },
    dureeSecond * 1000,
    "",
    function() {
      $("#Stop" + id).hide(1);
      $("#Play" + id).show(1);
      $("#PlayAuto" + id).show(1);
      $("#Pause" + id).hide(1);
      $("#PlayPauseResume" + id).hide(1);
      if (board === 0) {
        $("#sceneLight" + id).animate({ width: "10%" }, 1);
      } else {
        var lancerScene = false;

        board.lanes[1].cards.forEach(card => {
          if (lancerScene === true) {
            //appel recurcif de l'annimation de la scene

            PlayAutoScene(card, card, card, { board }, false);
            lancerScene = false;
          }
          if (card.id === id) {
            lancerScene = true;
          }
        });
      }
    }
  );
}

function StopAnimate() {
  $(".btnSceneStop").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });
  $(".btnScenePlay").each(function() {
    $(this)
      .stop(false, false)
      .show(1);
  });

  $(".maskScene").each(function() {
    $(this)
      .stop(false, false)
      .css({ left: 0 });
  });

  $(".sceneLight").each(function() {
    $(this)
      .stop(false, false)
      .width("10%");
  });
}

function PauseAnimate(id, idBdd) {
  console.log("send Pause Request scene " + idBdd);
  $("#Load" + id).pause();
  $("#sceneLight" + id).pause();
  $("#Mask" + id).pause();
}
//permet de lancer une scène.
//2 mode , lecture automatique ( enchainement des scènes)
//manual = lecture d'une scène
const PlayScene = (value, valueBdd, dureeSecond) => {
  $(".btnSceneStop").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });
  $(".btnScenePlay").each(function() {
    $(this)
      .stop(false, false)
      .show(1);
  });
  $(".btnScenePlayAuto").each(function() {
    $(this)
      .stop(false, false)
      .show(1);
  });
  $(".btnScenePause").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });

  //mode manuel

  $("#Stop" + value.id).show(1);
  $("#Play" + value.id).hide(1);
  Animate(value.id, dureeSecond.dureeSecond, 0, true);

  //appeleler l'API de votre système avec la méthode
  //fetch + paramètre.

  SendMessageToApi(valueBdd.idBdd);
  console.log("play Scene " + valueBdd.idBdd);
};

//on passe aussi l'id de la scène ou l'on veut reprendre la lecture
//click permet de savoir si c'est le User qui lance la fonction ou le susteme auto
const PlayAutoScene = (value, valueBdd, dureeSecond, board, click) => {
  $(".btnScenePlayPause").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });

  $(".btnScenePlayAuto").each(function() {
    $(this)
      .stop(false, false)
      .show(1);
  });

  $(".btnScenePlay").each(function() {
    $(this)
      .stop(false, false)
      .show(1);
  });
  $(".btnSceneStop").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });
  $(".btnScenePause").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });

  $(".btnScenePlayPauseResume").each(function() {
    $(this)
      .stop(false, false)
      .hide(1);
  });

  $("#Pause" + value.id).show(1);
  $("#PlayAuto" + value.id).hide(1);

  Animate(value.id, dureeSecond.dureeSecond, board.board, click);

  //appeleler l'API de votre système avec la méthode
  //fetch + paramètre.
  SendMessageToApi(valueBdd.idBdd);
  console.log("play Scene " + valueBdd.idBdd);
};

const PlayAutoSceneResume = (value, valueBdd) => {
  $("#Pause" + value.id).show(1);
  $("#PlayPauseResume" + value.id).hide(1);

  $("#Load" + value.id).resume();
  $("#sceneLight" + value.id).resume();
  $("#Mask" + value.id).resume();

  console.log("Resume Scene " + valueBdd.idBdd);
};

const PauseScene = (value, valueBdd, dureeSecond, board) => {
  $("#Pause" + value.id).hide(1);
  $("#PlayPauseResume" + value.id).show(1);
  PauseAnimate(value.id, valueBdd.idBdd);

  //appeleler l'API de votre système avec la méthode
  //fetch + paramètre.
};

const StopScene = () => {
  StopAnimate();
  $(".loading").each(function() {
    $(this)
      .stop(false, false)
      .width("10%");
  });
  console.log("Send Stop Scene");
  SendMessageToApi(7);
};

function App() {
  const [board, setBoard] = useState(boardData);
  const [idCard, setIdCard] = useState(99);
  const [autoPlay, setAutoPlay] = useState(false);

  //permet de charger les data du composant au chargement de la page
  useEffect(() => {
    laodPauseJquery();
    setBoard(board => boardData);
  }, []);

  //permet de definir le composant en lecture automatique
  const AutoScene = useCallback(() => {
    setAutoPlay(true);
    $("#AutoScene").hide(1);
    $("#ManualScene").show(1);
  }, []);

  //permet de definir le composant en lecture manuel
  const ManualScene = useCallback(() => {
    setAutoPlay(false);
    $("#AutoScene").show(1);
    $("#ManualScene").hide(1);
    StopScene();
  }, []);

  //methode permettant de rajouter une scènes dans l'etat
  const AddScene = useCallback(() => {
    //create scene
    var newId = idCard + 1;
    var Red = Math.floor(Math.random() * 255);
    var Green = Math.floor(Math.random() * 255);
    var Blue = Math.floor(Math.random() * 255);

    Red = Number(Red).toString(16);
    if (Red.length < 2) {
      Red = "0" + Red;
    }

    Green = Number(Green).toString(16);
    if (Red.length < 2) {
      Green = "0" + Green;
    }
    Blue = Number(Blue).toString(16);
    if (Red.length < 2) {
      Blue = "0" + Blue;
    }
    setIdCard(idCard => newId);
    var cards = {
      id: newId,
      idBdd: newId,
      title: "Scène" + newId,
      description: "Card content",
      Candelete: false,
      bgcolor: "#" + Red + "" + Green + "" + Blue + "",
      dureeSecond: 2,
      img: ""
    };
    var tempboard = board;
    const newBoard = addCard(tempboard, board.lanes[0], cards, {
      on: "bottom"
    });
    setBoard(board => newBoard);
  }, [board, idCard]);

  //méthode permettant de retirer une scène de l'etat
  const removeScene = useCallback(
    id => {
      var cards = id;
      var tempboard = board;
      var newBoard = removeCard(tempboard, board.lanes[1], cards);
      setBoard(board => newBoard);
    },
    [board]
  );

  //methode permettant de modifier l'ordre des scènes dans l'etat
  //on a rajouter le fait de dupliquer une scènes dans le cas d'un mouvement de la colonne 1 à 2
  //on a rajouter le fait d'avoir un bouton supprimer seulement sur les scenes de la colonne program
  const handleDeplaceScene = useCallback(
    (source, destination) => {
      var tempboard = board;
      //cas du déplacement d'une scène de la liste vers le program
      if (source.fromLaneId === 0 && destination.toLaneId === 1) {
        //duplication
        var newId = idCard + 1;
        setIdCard(idCard => newId);
        //TODO Recupérer les infor de la card
        //la recherché par position
        var lineID = source.fromLaneId;
        var indexCard = source.fromPosition;
        var CopyCard = board.lanes[lineID].cards[indexCard];
        var cards = {
          id: newId,
          idBdd: CopyCard.idBdd,
          title: CopyCard.title,
          description: CopyCard.description,
          Candelete: false,
          bgcolor: CopyCard.bgcolor,
          dureeSecond: CopyCard.dureeSecond,
          img: CopyCard.img
        };
        board.lanes[lineID].cards[indexCard].Candelete = true;
        tempboard = moveCard(tempboard, source, destination);

        tempboard = addCard(tempboard, board.lanes[0], cards);
      }
      //cas de de placement de la scène dans le program pour modifier sa position
      if (source.fromLaneId === 1 && destination.toLaneId === 1) {
        tempboard = moveCard(tempboard, source, destination);
      }

      //setIdCard(idCard);
      setBoard(board => tempboard);
    },
    [board, idCard]
  );

  return (
    <div>
      <Board
        onCardDragEnd={handleDeplaceScene}
        renderCard={(
          {
            title,
            description,
            id,
            Candelete,
            idBdd,
            bgcolor,
            dureeSecond,
            img
          },
          { removeCard, dragging }
        ) => (
          <div className="meter">
            <SceneCardBack bgcolor={bgcolor} img={img} />
            <SceneCardBackLight
              className="sceneLight"
              id={"sceneLight" + id}
              img={img}
            />
            <SceneCard dragging={dragging}>
              {Candelete === true ? (
                <img
                  className="btnDeleteScene"
                  src="http://tspro.fr/delete.png"
                  alt="playScene"
                  onClick={() => removeScene({ id })}
                />
              ) : null}
              <div className="loading" id={"Load" + id} />
              <div className="maskScene" id={"Mask" + id} />

              <div className="infoScene">
                <h1>{title}</h1>
                <h3>{description}</h3>

                {autoPlay === true && Candelete === true ? (
                  <div>
                    {" "}
                    <img
                      id={"PlayAuto" + id}
                      className="btnScene btnScenePlayAuto"
                      src="http://tspro.fr/play.png"
                      alt="playScene"
                      onClick={() => {
                        PlayAutoScene(
                          { id },
                          { idBdd },
                          { dureeSecond },
                          { board },
                          true
                        );
                      }}
                    />
                    <img
                      id={"PlayPauseResume" + id}
                      style={{ display: "none" }}
                      className="btnScene btnScenePlayPauseResume"
                      src="http://tspro.fr/playPause.png"
                      alt="playScene"
                      onClick={() => {
                        PlayAutoSceneResume(
                          { id },
                          { idBdd },
                          { dureeSecond },
                          { board }
                        );
                      }}
                    />
                    <img
                      id={"Pause" + id}
                      style={{ display: "none" }}
                      className="btnScene btnScenePause"
                      src="http://tspro.fr/pause.png"
                      alt="playScene"
                      onClick={() => {
                        PauseScene({ id }, { idBdd }, { dureeSecond });
                      }}
                    />
                  </div>
                ) : (
                  <div>
                    <img
                      id={"Play" + id}
                      className="btnScene btnScenePlay"
                      src="http://tspro.fr/play.png"
                      alt="playScene"
                      onClick={() => {
                        PlayScene({ id }, { idBdd }, { dureeSecond });
                      }}
                    />
                    <img
                      id={"Stop" + id}
                      style={{ display: "none" }}
                      className="btnScene btnSceneStop"
                      src="http://tspro.fr/stop.png"
                      alt="playScene"
                      onClick={() => {
                        StopScene({ id }, { idBdd }, { dureeSecond });
                      }}
                    />
                  </div>
                )}
              </div>
            </SceneCard>
          </div>
        )}
        renderLaneHeader={({ title, id }) => (
          <YourLaneHeader className="headerLane">
            <span>{title}</span>
            {id === 1 ? (
              autoPlay === true ? (
                <span> Auto</span>
              ) : (
                <span> Manual</span>
              )
            ) : null}
            {id === 1 ? (
              <div className="divBtnProgram">
                <img
                  id={"AutoScene"}
                  style={{ display: "block" }}
                  className="btnProgram"
                  src="http://tspro.fr/playPause.png"
                  alt="AutoScene"
                  onClick={AutoScene}
                />
                <img
                  id={"ManualScene"}
                  style={{ display: "none" }}
                  className="btnProgram"
                  src="http://tspro.fr/stop.png"
                  alt="ManualScene"
                  onClick={ManualScene}
                />
              </div>
            ) : null}
          </YourLaneHeader>
        )}
        disableLaneDrag={true}
        //initialBoard={board}
        children={board}
      />

      <button type="button" onClick={AddScene}>
        Add Card
      </button>
    </div>
  );
}
const laodPauseJquery = function() {
  var pauseId = "jQuery.pause",
    uuid = 1,
    oldAnimate = $.fn.animate,
    anims = {};

  function now() {
    return new Date().getTime();
  }

  $.fn.animate = function(prop, speed, easing, callback) {
    var optall = $.speed(speed, easing, callback);
    optall.complete = optall.old; // unwrap callback
    return this.each(function() {
      // check pauseId
      if (!this[pauseId]) this[pauseId] = uuid++;
      // start animation
      var opt = $.extend({}, optall);
      oldAnimate.apply($(this), [prop, $.extend({}, opt)]);
      // store data
      anims[this[pauseId]] = {
        run: true,
        prop: prop,
        opt: opt,
        start: now(),
        done: 0
      };
    });
  };

  $.fn.pause = function() {
    return this.each(function() {
      // check pauseId

      if (!this[pauseId]) this[pauseId] = uuid++;
      // fetch data
      var data = anims[this[pauseId]];
      if (data && data.run) {
        data.done += now() - data.start;
        if (data.done > data.opt.duration) {
          // remove stale entry
          delete anims[this[pauseId]];
        } else {
          // pause animation
          $(this).stop();
          data.run = false;
        }
      }
    });
  };

  $.fn.resume = function() {
    return this.each(function() {
      // check pauseId
      if (!this[pauseId]) this[pauseId] = uuid++;
      // fetch data
      var data = anims[this[pauseId]];
      if (data && !data.run) {
        // resume animation
        data.opt.duration -= data.done;
        data.done = 0;
        data.run = true;
        data.start = now();
        oldAnimate.apply($(this), [data.prop, $.extend({}, data.opt)]);
      }
    });
  };
};

const rootElement = document.getElementById("root");
ReactDOM.render(<App />, rootElement);
