inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵ĳ������ݽ��϶���һ����ֱ۴�ϸ��ľ��
������û�����á�һλ�𹤵�������ü�����������������
�ǶѲ�ǽ�Ϲ���һ�����ӣ�ǽ������һ�Ѳ񵶡�
LONG);

        set("exits",([
                "west" : __DIR__"shantang",
        ]));
        set("resource/water", 1);

        set("objects" , ([
                __DIR__"npc/huogong" : 1,
		"/d/wudu/obj/ganchai" : 2,
        ]));

        setup();
}
