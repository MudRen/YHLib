inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ��ʯ��·�ϣ������ȥ���Ǻ�Ժ�ˣ�����������
���������洫�����󷹲˵������������ǹ����ķ����������
ȥ�ǹ���������
LONG);
        set("no_fight", 1);
        set("exits", ([
          	"east" : __DIR__"guofu_shilu-2",
          	"south" : __DIR__"guofu_lang3",
          	"north" : __DIR__"guofu_shilu-3",
          	"west" : __DIR__"guofu_fanting",
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
