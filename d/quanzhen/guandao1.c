inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ�����������ͨ���书�򣬶��������ǳ����ǡ���
�ϵ����˺ܶ࣬����ǵ���ͷ�Լ����Լ���·����Ȼ�������
������õõ�����������һ�������ƥ���������߷ɳ۶�����
������һƬ��ɳ��
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "northeast": "/d/changan/nan-chengmen",
        ]));
        setup();
        replace_program(ROOM);
}
