inherit SHOP;

void create()
{
	set("short", "��徸�");
	set("long", @LONG
��徸������������������ĵ��̣���������װ�޵��൱��
�����£��Գ��������������󷽵����ɡ���������Ļ�����ȴ
����һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
��徸������������������ĵ��̣���������װ�޵��൱��
�����£��Գ��������������󷽵����ɡ�������Ļ�����к�
�ſ��ˣ�æ����ͷ�󺹡�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/luoyang/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
