import os
import logging.config
import json

def setup_logging(default_path='logging.json', default_level=logging.INFO, env_key='LOG_CFG'):
    """Setup logging configuration"""
    path = default_path
    value = os.getenv(env_key, None)
    if value:
        path = value
    if os.path.exists(path):
        with open(path, 'rt') as f:
            config = json.load(f)
        logging.config.dictConfig(config)
    else:
        logging.basicConfig(level=default_level)

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
            "filename": "info.log",
            "backupCount": 20,
            "encoding": "utf8"
        },

        "error_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "ERROR",
            "formatter": "simple",
            "filename": "errors.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },

        "ctptd_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "ctptd.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },
         "ctptickTrading_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "ctptickTrading.log",
            "maxBytes": 10485760,
            "backupCount": 20,
            "encoding": "utf8"
        },
        "ctpmd_handler": {
            "class": "logging.handlers.RotatingFileHandler",
            "level": "INFO",
            "formatter": "simple",
            "filename": "ctpmd.log",
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
        }
    },

    "root": {
        "level": "INFO",
        "handlers": ["console", "info_handler", "error_handler"]
    }
})

def getLogger(name=None):
    return logging.getLogger(name)


