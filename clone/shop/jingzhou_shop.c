inherit SHOP;

void create()
{
	set("short", "�廪¥");
	set("long", @LONG
�廪¥λ�ھ��ݳǱ��������ڴ˵Ķ����̸���֡�¥��װ
��÷ǳ����ž��£����ƾ��ݳ���һ����������ʱ����Ļ���
��ȴ����һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
�廪¥λ�ھ��ݳǱ��������ڴ˵Ķ����̸���֡�¥��װ
��÷ǳ����ž��£����ƾ��ݳ���һ��������Ļ�����к���
ǰ������Ŀ��ˣ�æ����ͷ�󺹡�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/jingzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
