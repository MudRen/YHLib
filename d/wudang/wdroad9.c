inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����������Ļ���·�ϣ����Ծ�����ɭɭ�����֡�
�����Ǻ������磬��˵���������˳�û�����ɾ���������ȥ
�������ϡ�
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "northwest" : __DIR__"sanbuguan",
                "south"     : __DIR__"wdroad10",
                "southeast" : "/d/henshan/hsroad8",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

