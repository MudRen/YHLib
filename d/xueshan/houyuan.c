inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǵ����µĺ�Ժ����Ժ�������˼������ѩ�ɣ���
�׻λε�ѩɽ�����£�����ƮȻ�������Ķ����ϱ߱��Ǵ�����
�����䳡�ˡ�
LONG);
        set("outdoors", "xueshan");
        set("exits", ([
                "northdown" : __DIR__"dilao",
                "south"     : __DIR__"chang3",
        ]));
        setup();
        replace_program(ROOM);
}
