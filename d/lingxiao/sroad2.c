inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��ʱѩ����Щ�ˣ�ʹ�õ��ϸ����˺���һ�㡣��ֵ������
������ɽ�����������ı���������̫���������ͷ��䣬������
�㶼���ǳ��ɫ��͸���壬��Щĩ�������ѩ������������£�
����ϼ�����ʣ�������������ݡ�ɽ·Ҳ������ƽ̹��������һ
�������������뵽��ʫ��˵����ȥʱѩ����ɽ·����Ҳ�������
�ɡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"southdown"  : __DIR__"sroad1",
            	"northup"  : __DIR__"sroad3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

