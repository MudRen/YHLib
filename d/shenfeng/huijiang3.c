inherit ROOM;

void create()
{
        set("short", "�Ͻ�С��");
        set("long", @LONG
�Ӳ�ԭ�����£���ӽ��Ͻ�ɳĮ�ˡ���������𽥸�����
��ʱ����ɳĮ��ӿ����ɳĮ�ﻹ���������̶ӣ��������Ϣ��
�������������������������ʮ�����֡�������һСԺ��
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
            	"northup" : __DIR__"huijiang2",
                "south" : __DIR__"huijiang6",
            	"west" : __DIR__"huijiang4",
            	"east" : __DIR__"huijiang5",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
