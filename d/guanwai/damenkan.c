#include <ansi.h>
inherit RIVER;

void create()
{
        set("short", "���ſ���");
        set("long", @LONG
�������ؽ��򶫵Ĺŵ�����Ϊ��ɽ�ɲεĲο����ߣ����
Ҳ�Ʋ�·��ǰ��һ��Сɽ�ض�ȥ·��Ϊ��ȥ�ɲεĵ�һ������
�ʱ���Ϊ���ſ��ӡ������ǿ������ɻ��� (river)���ɻ�����
����ʱ�������ͨ�У����ﻯ����ֻ���Ҵ��Ұ�æ�ˡ�
LONG);
        set("arrive_room", "/d/guanwai/chuanchang");
        set("exits", ([
                "southeast"  : __DIR__"ermenkan",
        ]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("outdoors", "guanwai");
        setup();
        replace_program(RIVER);
}
