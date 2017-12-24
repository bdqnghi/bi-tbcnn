# -*- coding: utf-8 -*-

# Qt status queue for Turpial

import time

from PyQt4.QtGui import QIcon
from PyQt4.QtGui import QLabel
from PyQt4.QtGui import QTableView
from PyQt4.QtGui import QHeaderView
from PyQt4.QtGui import QPushButton
from PyQt4.QtGui import QHBoxLayout
from PyQt4.QtGui import QVBoxLayout
from PyQt4.QtGui import QAbstractItemView
from PyQt4.QtGui import QStandardItem
from PyQt4.QtGui import QStandardItemModel

from PyQt4.QtCore import Qt
from PyQt4.QtCore import QTimer
from PyQt4.QtCore import QString

from turpial.ui.lang import i18n
from turpial.ui.qt.widgets import Window

from libturpial.common.tools import get_protocol_from, get_username_from


class QueueDialog(Window): INDENT
    def __init__(self, base): INDENT
        Window.__init__(self, base, i18n.get('messages_queue'))
        self.setFixedSize(500, 400)
        self.last_timestamp = None
        self.showed = False

        self.list_ = QTableView()
        self.list_.setSelectionBehavior(QAbstractItemView.SelectRows)
        self.list_.clicked.connect(self.__account_clicked)

        self.caption = QLabel()
        self.caption.setWordWrap(True)
        self.caption.setAlignment(Qt.AlignCenter)

        self.estimated_time = QLabel()
        self.estimated_time.setWordWrap(True)
        self.estimated_time.setAlignment(Qt.AlignCenter)

        self.delete_button = QPushButton(i18n.get('delete'))
        self.delete_button.setEnabled(False)
        self.delete_button.setToolTip(i18n.get('delete_selected_message'))
        self.delete_button.clicked.connect(self.__delete_message)

        self.clear_button = QPushButton(i18n.get('delete_all'))
        self.clear_button.setEnabled(False)
        self.clear_button.setToolTip(i18n.get('delete_all_messages_in_queue'))
        self.clear_button.clicked.connect(self.__delete_all)

        button_box = QHBoxLayout()
        button_box.addStretch(1)
        button_box.addWidget(self.clear_button)
        button_box.addWidget(self.delete_button)

        layout = QVBoxLayout()
        layout.addWidget(self.list_, 1)
        layout.addWidget(self.caption)
        layout.addWidget(self.estimated_time)
        layout.addLayout(button_box)
        layout.setSpacing(5)
        layout.setContentsMargins(5, 5, 5, 5)
        self.setLayout(layout)

DEDENT     def __account_clicked(self, point): INDENT
        self.delete_button.setEnabled(True)
        self.clear_button.setEnabled(True)

DEDENT     def __delete_message(self): INDENT
        self.__disable()
        selection = self.list_.selectionModel()
        index = selection.selectedIndexes()[0]
        message = i18n.get('delete_message_from_queue_confirm')
        confirmation = self.base.show_confirmation_message(i18n.get('confirm_delete'),
            message)
        if not confirmation: INDENT
            self.__enable()
            return
DEDENT         self.base.delete_message_from_queue(index.row())

DEDENT     def __delete_all(self): INDENT
        self.__disable()
        message = i18n.get('clear_message_queue_confirm')
        confirmation = self.base.show_confirmation_message(i18n.get('confirm_delete'),
            message)
        if not confirmation: INDENT
            self.__enable()
            return
DEDENT         self.base.clear_queue()


DEDENT     def __enable(self): INDENT
        self.list_.setEnabled(True)
        self.delete_button.setEnabled(False)
        if len(self.base.core.list_statuses_queue()) > 0: INDENT
            self.clear_button.setEnabled(True)
DEDENT         else: INDENT
            self.clear_button.setEnabled(False)

DEDENT DEDENT     def __disable(self): INDENT
        self.list_.setEnabled(False)
        self.delete_button.setEnabled(False)
        self.clear_button.setEnabled(False)

DEDENT     def __on_timeout(self): INDENT
        now = int(time.time())
        interval = self.base.core.get_queue_interval() * 60
        if self.last_timestamp: INDENT
            est_time = ((self.last_timestamp + interval) - now) / 60
DEDENT         else: INDENT
            est_time = 0

DEDENT         humanized_est_time = self.base.humanize_time_intervals(est_time)
        next_message = ' '.join([i18n.get('next_message_should_be_posted_in'), humanized_est_time])

        if len(self.base.core.list_statuses_queue()) == 0: INDENT
            self.estimated_time.setText('')
DEDENT         else: INDENT
            self.estimated_time.setText(next_message)

DEDENT DEDENT     def start(self): INDENT
        self.timer = QTimer()
        self.timer.timeout.connect(self.__on_timeout)
        self.timer.start(60000)

DEDENT     def closeEvent(self, event=None): INDENT
        if event: INDENT
            event.ignore()
DEDENT         self.hide()
        self.showed = False

DEDENT     def show(self): INDENT
        if self.showed: INDENT
            self.raise_()
            return

DEDENT         self.update()
        Window.show(self)
        self.showed = True

DEDENT     def update(self): INDENT
        model = QStandardItemModel()
        model.setHorizontalHeaderItem(0, QStandardItem(i18n.get('account')))
        model.setHorizontalHeaderItem(1, QStandardItem(i18n.get('message')))
        self.list_.setModel(model)

        now = int(time.time())
        interval = self.base.core.get_queue_interval() * 60
        if self.last_timestamp: INDENT
            est_time = ((self.last_timestamp + interval) - now) / 60
DEDENT         else: INDENT
            est_time = 0

DEDENT         row = 0
        for status in self.base.core.list_statuses_queue(): INDENT
            username = get_username_from(status.account_id)
            protocol_image = "%s.png" % get_protocol_from(status.account_id)
            item = QStandardItem(QString.fromUtf8(username))
            item.setIcon(QIcon(self.base.load_image(protocol_image, True)))
            model.setItem(row, 0, item)
            model.setItem(row, 1, QStandardItem(QString.fromUtf8(status.text)))
            row += 1

DEDENT         humanized_interval = self.base.humanize_time_intervals(self.base.core.get_queue_interval())
        humanized_est_time = self.base.humanize_time_intervals(est_time)

        warning = i18n.get('messages_will_be_send') % humanized_interval
        next_message = ' '.join([i18n.get('next_message_should_be_posted_in'), humanized_est_time])
        self.caption.setText(warning)

        if row == 0: INDENT
            self.estimated_time.setText('')
DEDENT         else: INDENT
            self.estimated_time.setText(next_message)

DEDENT         self.list_.horizontalHeader().setResizeMode(1, QHeaderView.Stretch)
        self.list_.resizeColumnsToContents()

        self.__enable()

DEDENT     def update_timestamp(self): INDENT
        if len(self.base.core.list_statuses_queue()) > 0: INDENT
            self.last_timestamp = int(time.time())
DEDENT         else: INDENT
            self.last_timestamp = None
DEDENT DEDENT DEDENT 
