#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����Ƭ�һ��ĺ�������һ���޼�ȫ��ʢ�����һ���΢��
��������Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С���
����һƬ�һ��֣���������һ��Сͤ�ӡ�
LONG);
       set("exits", ([
           "south" : __DIR__"tao0",
           "north" : __DIR__"haitan",
       ]));
       set("objects", ([
           CLASS_D("taohua")+"/feng" : 1,
       ]) );
    
       set("outdoors","taohua");
       setup();
       replace_program(ROOM);
}

