inherit ITEM;

#define FEITUO     "/clone/lonely/feituo"

void create()
{
        object ob;
	set_name("��Ǭ�ĺ���", ({ "Skeleton", "skeleton", "����" }));
        set_weight(500);
        set_max_encumbrance(800000);
        set("unit", "��");
        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
        set("value", 1);
        set("no_get", "�ⶫ��һ����ɢ�����Ǳ��ɣ�\n");
        if (clonep())
	{
        	set_default_object(__FILE__);
	        ob = find_object(FEITUO);
        	if (! ob) ob = load_object(FEITUO);
                if (! environment(ob))
                        ob->move(this_object());
    	}
}
