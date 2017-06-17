import os
import logging.config
import json

def __create_logging_path():
    path = 'logs/'
    if not os.path.exists(path):
        os.makedirs(path)

__create_logging_path()


logging.config.dictConfig({
    "version": 1,
    "disable_existing_loggers": False,
    "formatters": {
        "simple": {
            "format": "%(asctime)s %(name)s:%(lineno)d [%(thread)d] %(levelname)s %(message)s"
        }
    },

    "handlers": {
        "console": {
            "class": "logging.StreamHandler",
            "level": "DEBUG",
            "formatter": "simple",
            "stream": "ext://sys.stdout"
        },

        "info_handler": {
            "class": "logging.handlers.TimedRotatingFileHandler",
            "when": "D",
            "level": "INFO",
            "formatter": "simple",
            "filename": "logs/info.log",
            "backupCount": 20,
            "encoding": "utf8"
        },
        "error_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "ERROR",
            "formatter": "simple",
            "filename": "logs/errors.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },

        "ctptd_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "logs/ctptd.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },
         "test_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "logs/test.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },
         "ctptickTrading_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "logs/ctptickTrading.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },
        "ctpmd_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "logs/ctpmd.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        }
    },

    "loggers": {
        "quant.api.ctpx.ctptd": {
            "level": "INFO",
            "handlers": ["console", "ctptd_handler"],
            "propagate": False
        },
        "ctptickTrading": {
            "level": "INFO",
            "handlers": ["console", "ctptickTrading_handler"],
            "propagate": False
        },
        "quant.api.ctpx.ctpmd": {
            "level": "INFO",
            "handlers": ["console", "ctpmd_handler"],
            "propagate": False
        },

        "test": {
            "level": "INFO",
            "handlers": ["console", "test_handler"],
            "propagate": False
        },
    },

    "root": {
        "level": "INFO",
        "handlers": ["console", "info_handler", "error_handler"]
    }
})

def getLogger(name=None):
    return logging.getLogger(name)


