inherit ROOM;

void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ��СС���ӻ��̡����������ŵ�̺�����ϰ����ڵ�
̺�ϣ��Ա߶������Ļ���ǽ���и������Ǹ���Ŀ��
LONG);
        set("exits", ([ 
                "east" : __DIR__"beijiang",
        ]));
        set("objects", ([
                __DIR__"npc/maimaiti": 1
        ]) );
        setup();
        replace_program(ROOM);
}

 
