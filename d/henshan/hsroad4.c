inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ����������Ļ���·�ϣ�����������ɭɭ�����֡�
���治Զ���Ǻ����س��ˡ�����������һ�������
LONG );
        set("outdoors", "hengyang");

        set("exits", ([
                "east"  : __DIR__"hengyang11",
                "west"  : __DIR__"hsroad5",
        ]));

        setup();
        replace_program(ROOM);
}
