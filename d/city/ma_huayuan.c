inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
������һ��С��԰����Ȳ��ϸ�����Ժ�������ǧ�죬��
ȴҲ���õþ��¿��ˡ�ؤ������Ȼ��������֮ʿ���������һ�
ʢ�������ճ�����ɻ����������ջ����ޣ���������һƬ
��ѩ������԰��վ��һλ��ؤ��Ҳ��֪���ڸ�ʲô��
LONG);
        set("outdoors", "city");
        set("exits", ([
                "west"  : __DIR__"ma_xiaojing",
        ]));
        set("objects", ([
                CLASS_D("gaibang") + "/bai" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
