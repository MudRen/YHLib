inherit SHOP;

void create()
{
	set("short", "��ʸ�");
	set("long", @LONG
��ʸ������ɺ��ݳǽ������ɽ����������ν����������
�����պ��������ݳǽ������һ����ҵ���Ҳ�����⡣����
������ȴ����һ��������Ѻܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
��ʸ������ɺ��ݳǽ������ɽ����������ν����������
�����պ��������ݳǽ������һ����ҵ���Ҳ�����⡣����
װ��õ��ž��£���������������к��ſ��ˡ�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/hangzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
