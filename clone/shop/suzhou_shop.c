inherit SHOP;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ݳǱ������֮Ϊ����ʵ��ȴ��һ��װ��
���µĵ��̡����ݳǽ������һ����ҵ���Ҳ�����⡣����
������ȴ����һ��������Ѻܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
���������������ݳǱ������֮Ϊ����ʵ��ȴ��һ��װ��
���µĵ��̡����ݳǽ������һ����ҵ���Ҳ�����⡣��ʱ
���û����æ��æ�£��к��ſ��ˡ�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/suzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}

