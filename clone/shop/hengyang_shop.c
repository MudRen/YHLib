inherit SHOP;

void create()
{
	set("short", "ף�ھ�");
	set("long", @LONG
�����Ǻ������ڵ�һ�ҵ��̣���������С��������ɽȴ��
Ϊ�����������ɺ�ɽ���֮һ��ף�ڷ���������Ӻ�ľ�񴰷�
����ȥ�����������ų����������Ľֵ������۵ס�
LONG);
        set("open_long", @LONG
�����Ǻ������ڵ�һ�ҵ��̣���������С��������ɽȴ��
Ϊ�����������ɺ�ɽ���֮һ��ף�ڷ���������Ӻ�ľ�񴰷�
����ȥ�����������ų����������Ľֵ������۵ס�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/henshan/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
