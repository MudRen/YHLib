inherit ROOM;

void create()
{
        set("short", "ѩɽɽ·");
        set("long", @LONG
��ѩɽ��´�ĵ��Ʋ������ߣ���Χ����һЩСɽ������
��һ����Ժ��ɽ�������Ե��쳣�ߴ���Ժ��ƽ�����ͣ�����
��ʯ���ɣ�ǽ���ʵ������խС��
LONG );
        set("exits", ([
                "north"   : __DIR__"nroad3",
                "westup"  : "/d/xueshan/shanmen",
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

