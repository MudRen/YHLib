inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����ʯ����״�������أ�ǰխ�����Ϊ���Σ����߰�Բ
����ȴ��������״��ԭ��������ǰ������ʦ�������ң�ǰխ��
�ƣ����ʹȭ����Բ�н������Ƿ��ڡ������и�С�Ŷ���ͨ��
����������ҡ�
LONG);
        set("exits", ([
                "east"  : __DIR__"zhengting",
                "south" : __DIR__"liangong2",
        ]));
        set("for_family", "��Ĺ��");
        setup();
        replace_program(ROOM);
}
